using System.Runtime;

namespace StringForge.Test
{
    using NUnit.Framework;
    using ViewModel;

    [TestFixture]
    public class ConfigScannerViewModelTestFixture
    {
        private ConfigScannerViewModel vm;

        [SetUp]
        public void SetUp()
        {
            this.vm = new ConfigScannerViewModel();
        }

        [TearDown]
        public void TearDown()
        {
            this.vm = null;
        }

        [Test]
        public void VerifyThatTheModelIsSet()
        {
            this.vm.GetModel("classtest\\rhsusf_c_weapons");

            Assert.NotNull(this.vm.Model);
        }

        [Test]
        public void VerifyThatFiltersGetDecomposed()
        {
            this.vm.DecomposeFilters();

            Assert.AreEqual(2, this.vm.FilterArray.Count);

            this.vm.FilterString = "";
            this.vm.DecomposeFilters();
            Assert.AreEqual(0, this.vm.FilterArray.Count);

            this.vm.FilterString = "displayName";
            this.vm.DecomposeFilters();
            Assert.AreEqual(1, this.vm.FilterArray.Count);
            this.vm.FilterString = "displayName,descriptionShort";
            this.vm.DecomposeFilters();
            Assert.AreEqual(2, this.vm.FilterArray.Count);
        }

        [Test]
        public void VerifyThatModelGetsFiltered()
        {
            this.vm.GetModel("classtest\\rhsusf_c_weapons");

            Assert.NotNull(this.vm.Model);

            this.vm.FilterModel();

            Assert.AreNotEqual(0, this.vm.AllProperties.Count);
        }
    }
}
